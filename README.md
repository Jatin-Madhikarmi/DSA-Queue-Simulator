# Traffic Management System
A real-time traffic intersection simulation that demonstrates traffic management systems algorithms. The simulation includes different types of vehicles, traffic lights, and dynamic queue management.

# Features
1. Vehicle Handling: Vehicles are spwaned into their lanes upon arrival through the x,y coordinate system.
2. Visualizing of the real world traffic junction system.
3. Implementation of the priroty lane and the Traddic Management Sysytem resposne according to various conditions.

# Algoritms
1. Traffic Time
   (BL2, CL3, DL4) are the lanes from which the traffictime is calculated,the formula for it is (BL2 + CL3 + DL4)/3 *2  
   Whereas in the case of priorityLaneTime it calulated by the multiplying by 2 i.e priorityLaneTime*2
2. For the generation of the vehicles for each of the lane used a random number generated through the srand and rand function by adding the header files #include<cstdlib> and #include<ctime>.
3. For the Traffic Light Condition ,used either the traffictime for normal lane condition or priorityLaneTime for priority lane condition and rendered the lights accrodingly.
4. Used File Handlings for most parts of the programs such as Traffic Light for a priority lane conditions and after generating a random numbers we wrote them to the file and read them for the rendering the vehiles.
   Code Snippet

     ```bash
     float traffictime=0;
    std::string PriorityTimer;
    PriorityTimer="PriorityLaneTimer.txt";
    std::vector <std::string> fileNames={"VehiclesNoA.txt","VehiclesNoB.txt","VehiclesNoC.txt","VehiclesNoD.txt"};// Vector containing the files names 
    std::vector<int>randomValue(fileNames.size());// Vector for random number generation. 
    float priorityLaneTime=0.0f;
    for(int i=0;i<4;i++)
    {
        randomValue[i]=GetRandomValue();
        if(i!=0)
        {
            traffictime+=(randomValue[i]); // The traffic light timings are only considered for the roads B,C and D 
        }
        else
        {
            priorityLaneTime=randomValue[i];
            if(priorityLaneTime > 10)
            {
                priorityLaneTime=priorityLaneTime * 2;
                UpdateFile(priorityLaneTime,PriorityTimer);
            }
        }
        UpdateFile(randomValue[i],fileNames[i]);
    }
    ```
# Data Structures Used
Since we were told to implement a Queue which is an ADT and Abstract Data Type (ADT) are defined as a data structure defined by its behavior rather han its implementation. So opted to go for Vector due to 
Easy to Use for dynamic allocation where values are read from the file and memory are allocated accordingly and don't have to worry about the memory dellocation.

   ```bash
      arr1.resize(state,x1);
    brr1.resize(state,y1);
    arr2.resize(state,x2);
    brr2.resize(state,y2);
    int coordinates1=0;
    int coordinates2=0;
    for(int i=0;i<state;i++)
    {
        arr1[i]=x1-coordinates1;
        coordinates1+=1000;
        arr2[i]=x2-coordinates2;
        coordinates2+=100;
    }
    //resize function for easy sizing of the vector depending upon the value of state which is read from the file.
    //easy access to each elements in the vector.
    //NOTE : x1,y1 represents the x and y coordinates of the lane 3 which are free to turn left on any conditions whether re or green light.
    & x2 and y2 represents the x and y coordintes of lane 2 which have a restricted movement.
```

# Preview
It may take some time due to the file being large please be patient.

![Image](https://github.com/user-attachments/assets/ebb981a5-e68f-4761-8450-7aae048d6cc8)
![Image](https://github.com/user-attachments/assets/1bae00cd-6660-46bd-bbac-ecbc8ac79d42)


# File Structures
```bash
.vscode/ 
   │── .gitkeep 
   │── c_cpp_properties.json 
   │── launch.json 
   │── settings.json 
   │── tasks.json 
lib/ 
   │── libgcc_s_dw2-1.dll 
   │── libstdc++-6.dll 
src/ 
   │── Dummy.cpp 
   │── Dummy.hpp 
   │── GenerateLaneCVehicles.cpp 
   │── GenerateLaneCVehicles.hpp 
   │── GenerateLaneDVehicles.cpp 
   │── GenerateLaneDVehicles.hpp 
   │── GenerateLanes.cpp 
   │── GenerateLanes.hpp 
   │── GeneratingLaneAVehicles.cpp 
   │── GeneratingLaneAVehicles.hpp 
   │── GeneratingLaneBVehicles.cpp 
   │── GeneratingLaneBVehicles.hpp 
   │── main.cpp 
preview.jpg 
.gitattributes 
.gitignore 
A&BTrafficLight.txt 
D&CTrafficLight.txt 
main.code-workspace 
Makefile 
PriorityLaneTimer.txt 
README.md 
VehiclesNoA.txt 
VehiclesNoB.txt
VehiclesNoC.txt 
VehiclesNoD.txt

```
# Use Files
The important files that helps for the rendering,updating and deleting.
In the src folders
1. Dummy.cpp and Dummy.hpp for checking and implementing and testing purpose mo actaul need
2. GenerateLaneCVehicle.cpp and GenerateLaneCVehicle.hpp for the rendering,updating and deleting the vehicles in raod C
3. GenerateDVehciles.cpp and GenerateDVehciles.hpp for the rendering,updating and deleting the vehicles in raod D
4. GenerateLanes.cpp and  GenerateLanes.hpp for the rendering the roads and also updating the traffic lights.
5. GeneratingLaneAVehicles.cpp and GeneratingLaneAVehicles.hpp for the rendering,updating and deleting the vehicles in raod A
6. GeneratingLaneBVehicles.cpp and GeneratingLaneBVehicles.hpp for the rendering,updating and deleting the vehicles in raod B

Outside the src folder
A&BTrafficLight.txt Stores the traffic light state for the road A and B
D&CTrafficLight.txt Stores the traffic light state for the road D and C
PriorityLaneTimer.txt Stores the priority lane timing
VehiclesNoA.txt Contains the a random number which is the number of vehicles in raod A 
VehiclesNoB.txt Contains the a random number which is the number of vehicles in raod B
VehiclesNoC.txt Contains the a random number which is the number of vehicles in raod C
VehiclesNoD.txt Contains the a random number which is the number of vehicles in raod D

# Functions 
In the file
1. GenerateLanes.cpp and  GenerateLanes.hpp the fucntions used are
   Lanes(); Construtor fucntion for initializing the coordinates.
   void Update(int); Checks whether to use the prioritytimer or normal traffic timer and updates the traffcilight state in the A&BTrafficLight.txt and D&CTrafficLigh.txt and use those updated values to continously to render the traffic                       light onto the screen.
   void Draw(); Firstly draws the lane and the light traffic light condition.
   i.e Whenever Update() chagnes it also affects the Draw() and also A&BTrafficLight.txt, D&CTrafficLight.txt

2.GenerateLaneCVehicle.cpp and GenerateLaneCVehicle.hpp the function used are:
   LaneC(int x1,int y1,int x2,int y2,int speed,int size); x1,y1 represents the x,y coordinate for the vehicle that are free to turn left. x2,y2 represents the x,y cordinate for the outgoing vehicles, speed and size refers to the speee                                                             and size of the vechicle respectively.
   void readStateFromFile(); Reads the value in the file D&CTrafficLight.txt for the trafficlight state.
   void update(); Updates the vehicles position depending uopn the value in the D&CTrafficLight.txt file and also responsible for deleting the vehciles (dequeue process) from the screen.
   void draw(); Renders the vehcile in accordance to the update() fucntion

<B>NOTE: The files responsible for the creating,updating and deleting the vehicles all have the same fucntion.Yes,Inheritance can be used in such case but some bugs occurred so created separate files whilist having the same functins.
For road A reads the file A&BTrafficLight.txt
For road B reads the file A&BTrafficLight.txt
For road C reads the file D&CTrafficLight.txt
For road D reads the file D&CTrafficLight.txt
</B>


# How to Use?
1. Raylib must be installed on your device.If not installed visit <a href="https://www.raylib.com">Raylib Installation.</a>
2. Clone the repository using the following command:

```bash
git clone https://github.com/Jatin-Madhikarmi/DSA-Queue-Simulator.git
```
3. Open the src folder and browse thorugh the folder and simply run the main.cpp file by pressing fn+F5 
