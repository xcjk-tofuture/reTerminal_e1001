SET( SOURCES
    Behaviour/GUI_Animations.c
    Behaviour/GUI_Events.c
    Content/assets/fonts/font_1.c
    Content/assets/styles/GUI_GlobalStyles.c
    Content/screens/screen.c
    GUI.c
    GUI_Variables.c
    ui_helpers.c
)

add_library( GUI ${SOURCES} )

