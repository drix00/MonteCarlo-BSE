macro(enable_python_venv)
    option(ENABLE_PYTHON_VENV "Enable Python venv in the project" ON)
    if (ENABLE_PYTHON_VENV)
        find_package (Python3 COMPONENTS Interpreter)
        execute_process (COMMAND "${Python3_EXECUTABLE}" -m venv "venv")

        ## update the environment with VIRTUAL_ENV variable (mimic the activate script)
        set (ENV{VIRTUAL_ENV} "venv")
        ## change the context of the search
        set (Python3_FIND_VIRTUALENV FIRST)
        ## unset Python3_EXECUTABLE because it is also an input variable (see documentation, Artifacts Specification section)
        unset (Python3_EXECUTABLE)
        ## Launch a new search
        find_package (Python3 COMPONENTS Interpreter Development)
    endif ()
endmacro()
