library(shiny)
library(shinydashboard)
ui <- dashboardPage(
  dashboardHeader(title = "Table Output"),
  dashboardSidebar(),
  dashboardBody(
    box(tableOutput("table"))
  )
)
server <- function(input, output) {
  output$table <- renderTable({
    mtcars
  })
}
shinyApp(ui, server)