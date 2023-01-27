# Smooth area detection

<p align="center">
   <br>
   <img src="Images/1_Demonstration.jpg" width="70%" height="70%">
   <br>
</p>

# User interface
The program is able to detect smooth area within the image, to increase flexibility there're some parameters available for the user to define how smooth and how large the area to be detected.

**Default configuration** <br>
By clicking on "file->Open" to load image, then click on "Edit->Control_panel" to enable the control panel for customize usage, the parameters is adjustable and is initiated with default configuration:

<p align="center">
   <br>
   <img src="Images/2_Control_panel_default_configuration.jpg" width="70%" height="70%">
   <br>
</p>

**Criteria for smoothness** <br>
To define smoothness of the area is sometimes subjective or depending on application, this motivated me to invoke the concept of entropy for the situation, here the user is able to define smoothness by sliding the bar to interactively see the changes been made:

<p align="center">
   <br>
   <img src="Images/3_Control_panel_increasing_criteria.jpg" width="70%" height="70%">
   <br>
</p>

**Grid sizes** <br>
To adjust the sizes of the grid is also available, this determine how precise the detection unit should be and the overall amount of rectangles generated:

<p align="center">
   <br>
   <img src="Images/4_Control_panel_increasing_grid_sizes.jpg" width="70%" height="70%">
   <br>
</p>

# Implementation <br>
Recall the concept of entropy determines the amount of information of an event, an event that is guranteed to happened is considered small information content(which corresponds to the histogram of smooth area), meanwhile an event that contains high amount of uncertainty is considered high information content(which corresponds to the histogram of compound area), this is the key concept using throughout the project:

<p align="center">
   <br>
   <img src="Images/5_Entropy.jpg" width="70%" height="70%">
   <br>
</p>

