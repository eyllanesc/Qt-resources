import qbs 1.0

QtGuiApplication { // Product subtype
    name: "Demo"
    targetName: "ex-qbs-project"
    files: "main.cpp"
    Depends { name: "cpp", "Qt.widgets" } // 2 modules
    // Possible to define any rules, how files are handled
//    Group {
//        condition: qbs.targetOS.contains("windows")
//        files: [ "aFile_win.cpp" ]
//        fileTags: ["cpp"]
//    }
    Group {
        condition: qbs.targetOS.contains("linux")
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: ".."
    }
}









