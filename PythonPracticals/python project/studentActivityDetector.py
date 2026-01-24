import cv2
import mediapipe as mp

cap = cv2.VideoCapture("a.mp4")  # CCTV footage

mp_face_detection = mp.solutions.face_detection
face_detection = mp_face_detection.FaceDetection(model_selection=1, min_detection_confidence=0.3)

# Track students' attentiveness
inactivity_counter = {}
MAX_INACTIVITY_FRAMES = 30  # if face not detected for 30 frames -> mark as not attentive

while True:
    ret, frame = cap.read()
    if not ret:
        print("Video ended or file not found.")
        break

    # Upscale frame for better small-face detection
    frame = cv2.resize(frame, None, fx=2, fy=2, interpolation=cv2.INTER_CUBIC)

    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    results = face_detection.process(rgb)

    h, w, _ = frame.shape

    if results.detections:
        for face_id, detection in enumerate(results.detections):
            bboxC = detection.location_data.relative_bounding_box
            x1, y1 = int(bboxC.xmin * w), int(bboxC.ymin * h)
            x2, y2 = int((bboxC.xmin + bboxC.width) * w), int((bboxC.ymin + bboxC.height) * h)

            # Reset inactivity counter (face seen again)
            inactivity_counter[face_id] = 0

            # Mark as attentive
            color = (0, 255, 0)
            status = "Attentive"

            cv2.rectangle(frame, (x1, y1), (x2, y2), color, 2)
            cv2.putText(frame, f"{status}", (x1, y1 - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.8, color, 2)

    # If no faces detected in this frame, increase inactivity count
    else:
        for fid in list(inactivity_counter.keys()):
            inactivity_counter[fid] += 1
            if inactivity_counter[fid] > MAX_INACTIVITY_FRAMES:
                # Draw a warning on screen (global for now)
                cv2.putText(frame, "Not Attentive", (50, 100),
                            cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 3)

    cv2.imshow("CCTV Classroom Attentiveness", frame)
    if cv2.waitKey(30) & 0xFF == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()
