# Development

 - **4/18/20** Cloned Git Repository and begin CPR integration
   - Asked on piazza for clarification in creating submodules
   - Still have to complete CPR library integration
   
 - **4/19/20** Continued integrating CPR library
   - Executed terminal commands to include submodule
   - Added CPR library to project 
   - Investigated OpenSSL errors for CPR
   
 - **4/20/20** Completed integration CPR library and Built Storage for API Data
   - Resolved OpenSSL issue for CPR
   - Resolved issues with #include filepath in CPR submodule
   - Had to utilize Terminal and change CMake configurations to integrate CPR as a submodule
   - Created FinanceData class to store API finance data
 
 - **4/23/20** Created finance_geometry.h for Geometry Class
   
 - **4/24/20** Developed Additional Functionality for Producing Geometry
   - Completed implementations of Geometry class
   - Refactored various file names
   
 - **4/27/20** Fixed Library Integration Issues and Interact with API Calls
   - Fixed OpenSSL (used with CPR) issues in CMake
   - Included nlohmann_json library
   
 - **4/29/20** Added Cinder Blocks and Develop UI
   - Incorporated ImGui CinderBlock for accepting user inputs to make API calls
   - Created Window using ImGui to accept user inputs. This is used to create custom API calls for 
   whatever stock the user chooses.
   
 - **4/30/20** Developed UI Interaction Between User and Geometry and created logic for storing
 data from API calls
    - Connect user inputs from ImGui window into FinanceData and Geometry classes
    - Created logic for using user input to create custom API calls.
    - Created variables to store custom API call data.
   
 - **5/1/20** Developed functioning UI and API, and improved object decomposition.
    - Created logic to parse API calls and store data in FinanceData objects.
    - Created logic for building multiple geometrical shapes based on which textfield user interacted with.
    - Now, UI displays custom geometry, changing edge numbers and colors based on user's stock input 
    and API response.
    - Created various helper functions for better object decomposition.
    - Fine tune Geometry class variables and functions for more clear data visualization.
    - Still need to fine tune geometrical colors/edge numbers for greater clarity and further
     decompose some repetitive code.
   
   
   
