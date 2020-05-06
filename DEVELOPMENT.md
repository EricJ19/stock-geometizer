# Development

 - **4/18/20** Cloned Git Repository and begin CPR integration
   - CPR repository recommends using submodules.
   - Asked on piazza for clarification in creating submodules
   - Still have to complete CPR library integration
   
 - **4/19/20** Continued integrating CPR library
   - Executed terminal commands to include CPR as a submodule.
   - Added CPR library to project 
   - It turns out CPR doesn't have their own Transport Layer Security (TLS) necessary for API calls, 
   so OpenSSL is necessary.
   - Investigated OpenSSL path finding errors for CPR on Piazza and StackOverflow. 
   It seems files are not found from OpenSSL. Issue still needs to be resolved.
   
 - **4/20/20** Completed integration CPR library and Built Storage for API Data
   - Resolved OpenSSL path finding issue for CPR. Found through Piazza and online that directory needed
   to be set in CMake configurations.
   - Resolved issues with #include filepath in CPR submodule. 
   - Created FinanceData class to store API finance data. Class structure made sense to create organized,
   independent data sets to be easily used to create unique geometry.
 
 - **4/23/20** Created finance_geometry.h for Geometry class
   - finance_geometry.h  complements the FinanceData class so that every FinanceData object is paired
   with a Geometry class. Design-wise it makes it easier to manipulate finance data and geometry information
   separately and then linking these objects later.
   
 - **4/24/20** Developed Additional Functionality for Producing Geometry
   - Completed implementations of Geometry class. Methods to scale mathematical values from finance data to 
    attain a reasonable geometrical shapes were found online and integrated to functions.
   - Refactored various file names to be more project-specific.
   
 - **4/27/20** Fixed Library Integration Issues and Interact with API Calls
   - Fixed OpenSSL (used with CPR) issues in CMake with the aid of Code Review mentor.
   - It turns out, for OS X users (which was used), system cURL had to be linked agains to enable
    OpenSSL to work.
   - API responses were in the form of JSON and so nlohmann_json library was added.
   
 - **4/29/20** Added Cinder Blocks and Develop UI
   - Cinder by itself didn't have a method to analyze text inputs from users. PreztelGui and ImGui Cinderblocks
   were suggested on Piazza and so they were explored online.
   - ImGui CinderBlock was chosen and incorporated accepting user inputs to make API calls. ImGui appeared easy
   to set up and was designed to complement programs with geometrical elements.
   - Created Window using ImGui to accept user inputs. This is used to create custom API calls for 
   whatever stock the user chooses.
   
 - **4/30/20** Developed UI Interaction Between User and Geometry and created logic for storing
 data from API calls
    - Connect user inputs from ImGui window into FinanceData and Geometry classes. This was fairly easy
    due to the FinanceData and Geometry classes structure.
    - Created logic for using user input to create custom API calls.
    - Created JSON variables to store custom API call data. Still have to parse JSON ad
    store data into FinanceData objects.
   
 - **5/1/20** Developed functioning UI and API, and improved object decomposition.
    - Created logic to parse API calls and store data in FinanceData objects.
    - API responses were varied: some were 1-D arrays while others were 2-D. Thus,
    these needed to be parsed differently and methods to do this were found on Piazza and online.
    - There was a previous issue that the inner and outer shapes for the Geometry class covered up
    each other in the UI. Turns out, the outer shape needed to be drawn first so the inner shape could be
    drawn on top without being covered.
    - Created logic for building multiple geometrical shapes based on which textfield user interacted with.
    - Now, UI displays custom geometry, changing edge numbers and colors based on user's stock input 
    and API response.
    - Created various helper functions for better object decomposition.
    - Fine tuned Geometry class variables and functions for more clear data visualization.
    Constants in Geometry class for edge numbers were too large and it was previously hard to distinguish one
    shape with another.
    - Still need to fine tune geometrical colors numbers for greater clarity and further
     decompose some repetitive code. Because RGB was used the red and green indicated mixed to create
     blueish colors in some cases which may be unclear.
     
 - **5/2/20** Fix UI errors, fine tune UI, and continue improving object decomposition.
    - Now supports three geometrical shapes without previous error where only one shape responded to user inputs.
    - My goal was to create geometry that would be easily differentiable between unique stocks. 
        - To do this, the coloring and edge number is more unique to each stock. 
        - The range of yellow colors increased so it's not just red or green, there is a probably chance it is yellow.
        - The Max/Min constants were larger so more unique stock shapes can be created based on stock attributes.
        
- **5/3/20** Fix various bugs and improve the UI.
    - Fixed API response error for stocks that were not valid.
        - Turns out, getting the CPR response wont produce an exception even for an invalid URL, 
        but parsing the response using nlohmann_json can produce an exception. So Try Catch statement
        was modified around parsing rather than receiving the response.
    - Modified various constants for Geometry class to make stocks more differentiable. This was important
    from a functionality perspective as easier differentiation makes it easier to compare different stocks.
    
- **5/4/20** Improve object decomposition
    - Better utilize the FinanceData class by changing the function parameters in Geometry class to
    simply accept a FinanceData object rather than ex. 26 Week Price Return from the return value of a function 
    in FinanceData.
 
- **5/6/20** Polish UI and Update README.md
    - Change ImGui so the InputText information fits onto the window
    - Modify color/edge constants for more differentiated stocks, which is important to more easily compare
    stocks.
   
   
   
