#### Added 2 room types: random jump room and selection jump room

Random jump room: Enter this room and be randomly teleported to a room other than room0

Select jump room: enter this room, prompt to enter the id to jump to the room corresponding to the id

#### random jump room, selection jump room, rooms with princesses, and rooms with monsters are randomly generated according to random seeds about time

```c++
srand(time(0));
            princess_room = random_room_index();
            do {
                monster_room = random_room_index();
                random_jump_room = random_room_index();
                selective_jump_room = random_room_index();
            } while (monster_room == princess_room || random_jump_room == princess_room || random_jump_room == monster_room ||
                selective_jump_room == princess_room || selective_jump_room == monster_room || selective_jump_room == random_jump_room);
            rooms[princess_room].name = "secret room";
            rooms[monster_room].name = "over";
            rooms[monster_room].exits[0] = -1;
            rooms[monster_room].exits[1] = -1;
            rooms[monster_room].exits[2] = -1;
            rooms[monster_room].exits[3] = -1;
            rooms[random_jump_room].name = "random jump room";
            rooms[selective_jump_room].name = "selective jump room";
```

#### room structure

In the `castle.txt` folder like:

```shell
16 # means there are 16 rooms  
lobby 5 4 -1 -1 # The room number of the lobby's southeast and northwest, negative numbers(-1) are disconnected on the surface
room1 2 5 0 -1
room2 3 6 1 -1
room3 4 7 2 -1
...
```

What I construct here is a $4 \times 4$ square castle, but in fact, you can modify `castle.txt` to construct any style of room.

The export of castle is the north exit of lobby.
