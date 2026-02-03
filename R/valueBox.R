library(shiny)
library(shinydashboard)
ui <- dashboardPage(
  dashboardHeader(title = "Value Box"),
  dashboardSidebar(),
  dashboardBody(
    valueBox(
      value = 150,
      subtitle = "Students",
      icon = icon("users"),
      color = "blue"
    )
  )
)

server <- function(input, output) {}
shinyApp(ui, server)
