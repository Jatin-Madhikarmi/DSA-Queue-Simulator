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
      arr1.resize(state,x1);//
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
    //resize function for easy sizing of the vector depedngin upn the value of state which is read from the file.
    //easy access to each elements in the vector.
    //NOTE : x1,y1 represents the x and y coordinates of the lane 3 which are free to turn left on any conditions whether re or green light.
    & x2 and y2 represents the x and y coordintes of lane 2 which have a restricted movement. 

# Preview
![Image](https://github.com/user-attachments/assets/1bae00cd-6660-46bd-bbac-ecbc8ac79d42)

# How to Use?
1. Raylib must be installed on your device.If not installed visit <a href="https://www.raylib.com">Raylib Installation.</a>
2. Clone the repository using the following command:

```bash
git clone https://github.com/Jatin-Madhikarmi/DSA-Queue-Simulator.git
```
