library(shiny)
library(shinydashboard)
ui <- dashboardPage(
  dashboardHeader(title = "Interactive Dashboard"),
  dashboardSidebar(
    selectInput("var", "Select Variable",
                choices = colnames(mtcars))
  ),
  dashboardBody(
    box(plotOutput("plot"))
  )
)
server <- function(input, output) {
  output$plot <- renderPlot({
    hist(mtcars[[input$var]])
  })
}
shinyApp(ui, server)
