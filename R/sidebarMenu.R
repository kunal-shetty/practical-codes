library(shiny)
library(shinydashboard)
ui <- dashboardPage(
  dashboardHeader(title = "Sidebar Menu"),
  dashboardSidebar(
    sidebarMenu(
      menuItem("Home", tabName = "home"),
      menuItem("Data", tabName = "data")
    )
  ),
  dashboardBody(
    tabItems(
      tabItem(tabName = "home", h3("Home Page")),
      tabItem(tabName = "data", h3("Data Page"))
    )
  )
)

server <- function(input, output) {}
shinyApp(ui, server)
