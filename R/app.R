library(shiny)
library(shinydashboard)

ui <- dashboardPage(
  
  dashboardHeader(title = "Kunal"),
  
  dashboardSidebar(
    sidebarMenu(
      menuItem("Home", tabName = "home"),
      menuItem("Details", tabName = "details")
    ),
    
    br(),
    
    selectInput(
      inputId = "choice",
      label = "Select Option",
      choices = c("Option A", "Option B", "Option C")
    )
  ),
  
  dashboardBody(
    tabItems(
      
      tabItem(
        tabName = "home",
        fluidRow(
          box(
            title = "Box 1",
            width = 6,
            status = "primary",
            solidHeader = TRUE,
            textOutput("selected")
          ),
          box(
            title = "Box 2",
            width = 6,
            status = "info",
            solidHeader = TRUE,
            "Box"
          )
        )
      ),
      
      tabItem(
        tabName = "details",
        fluidRow(
          box(
            title = "Details Box",
            width = 12,
            status = "success",
            solidHeader = TRUE,
            "Detaills"
          )
        )
      )
      
    )
  )
)

server <- function(input, output) {
  
  output$selected <- renderText({
    paste("You selected:", input$choice)
  })
  
}

shinyApp(ui, server)
