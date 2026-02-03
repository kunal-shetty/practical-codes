library(shiny)
library(shinydashboard)
ui <- dashboardPage(
  dashboardHeader(title = "Plot Output"),
  dashboardSidebar(),
  dashboardBody(
    box(plotOutput("plot"))
  )
)
server <- function(input, output) {
  output$plot <- renderPlot({
    plot(mtcars$hp, mtcars$mpg,
         xlab = "HP",
         ylab = "MPG")
  })
}
shinyApp(ui, server)