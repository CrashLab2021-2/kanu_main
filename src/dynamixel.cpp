#ifndef DYNAMIX_CPP
#define DYNAMIX_CPP

void openDoor(){
    door_srv.request.signal = true;
    if(door_client->call(door_srv)){
        if(door_srv.response.isOpen)
            ROS_INFO("Door is Open!!");
        else
            ROS_INFO("Door is Close!!");
    }
    else ROS_ERROR("Failed");
}

void closeDoor(){
    door_srv.request.signal = false;
    if(door_client->call(door_srv)){
        if(door_srv.response.isOpen)
            ROS_INFO("Door is Open!!");
        else
            ROS_INFO("Door is Close!!");
    }
    else ROS_ERROR("Failed");
}

void tilteUp(){
    tile_srv.request.angle = 1180;
    if(!tilte_client->call(tile_srv))
        ROS_ERROR("Failed");
}

void tilteDown(){
    tile_srv.request.angle = 0;
    if(!tilte_client->call(tile_srv))
        ROS_ERROR("Failed");
}

void dispenser(){
    if(!dispenser_client->call(dispenser_srv))
        ROS_ERROR("Failed");
}

#endif