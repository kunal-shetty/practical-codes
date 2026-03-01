data$result = ifelse(data$Marks > 70, "Pass", "Fail")

newRow = data.frame(Name="Vinit", Age=19, Address="Kandivali", RollNumber=25322, Gender="M", Marks=80, result="Pass")