if(EXISTS "C:/Users/RC1ki/OneDrive/Documents/Uni/Imperative Programming/IPC031_2022_assignment_6_files/build/Assignment6_test[1]_tests.cmake")
  include("C:/Users/RC1ki/OneDrive/Documents/Uni/Imperative Programming/IPC031_2022_assignment_6_files/build/Assignment6_test[1]_tests.cmake")
else()
  add_test(Assignment6_test_NOT_BUILT Assignment6_test_NOT_BUILT)
endif()
