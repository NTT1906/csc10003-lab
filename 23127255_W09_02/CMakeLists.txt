cmake_minimum_required(VERSION 3.29)
project(23127255_W09)

set(CMAKE_CXX_STANDARD 11)
set(STUDENT_ID 23127255)
set(ASSIGNMENT_AMOUNT 2)

set(FOLDER_PREFIX "Assignment")

function(add_assignment executable_name source_path)
#	if (NOT EXISTS "${source_path}/")
	# Collect all source files in the specified directory
	file(GLOB_RECURSE SOURCES "${source_path}/*.cpp")

	if (NOT SOURCES)
		message(STATUS "${source_path} is empty.")
		return()
	endif ()

	# Add the executable
	add_executable(${executable_name} ${SOURCES})

#	 Include the source path as an include directory
#	target_include_directories(${executable_name} PRIVATE ${source_path})
endfunction()

function(create_assignments_folders_and_files folder_prefix)
	foreach(i RANGE 1 ${ASSIGNMENT_AMOUNT})
		# Create assignment folder
		if(i LESS 10)
			set(i_padded "0${i}")
		else()
			set(i_padded "${i}")
		endif()
#		string(FORMAT "%02d" i_padded ${i})
		set(assignment_folder "${PROJECT_SOURCE_DIR}/${folder_prefix}${i_padded}")
		if (NOT EXISTS ${assignment_folder})
			file(MAKE_DIRECTORY ${assignment_folder})
		endif ()

		# Create the placeholder file
		set(placeholder_file "${assignment_folder}/${STUDENT_ID}_Ex${i_padded}.cpp")
		if (NOT EXISTS ${placeholder_file})
			file(WRITE ${placeholder_file} "#include <iostream>\nusing namespace std;\n\nint main() {\n\treturn 0;\n}")
		endif ()
	endforeach()
endfunction()

create_assignments_folders_and_files(${FOLDER_PREFIX})

foreach (i RANGE 1 ${ASSIGNMENT_AMOUNT})
	if(i LESS 10)
		set(i_padded "0${i}")
	else()
		set(i_padded "${i}")
	endif()
#	string(FORMAT "%02d" i_padded ${i})
	set(assignment_folder "${folder_prefix}${i_padded}")

	add_assignment(Assignment${assignment_folder} Assignment${assignment_folder})
endforeach ()
