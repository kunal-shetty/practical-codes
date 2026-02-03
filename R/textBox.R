library(shiny)
library(shinydashboard)
ui <- dashboardPage(
  dashboardHeader(title = "Main Text"),
  dashboardSidebar(),
  dashboardBody(
    box(
      title = "Introduction",
      status = "primary",
      solidHeader = TRUE,
      "This is the main text displayed inside a box."
    )
  )
)
server <- function(input, output) {}
shinyApp(ui, server)