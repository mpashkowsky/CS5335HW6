
#include <iostream>
#include <thread>
#include <math.h>

#include "robot.hh"
#include "viz.hh"

using std::cout;
using std::endl;

void
callback(Robot* robot)
{
    cout << "\n===" << endl;
    for (auto hit : robot->ranges) {
        if (hit.range < 100) {
            float rel_x = (hit.range)*cos(hit.angle);
            float rel_y = (hit.range)*sin(hit.angle);
            float curr_x = rel_x + robot->pos_x;
            float curr_y = rel_y + robot->pos_y;
            float tot_range = sqrt(curr_x*curr_x+curr_y*curr_y);
            cout<< "tot_range " << tot_range << endl;
            float tot_angle = atan2(curr_x, curr_y);
            tot_angle = fmod((tot_angle + 3.14), 3.14);
            cout<< "tot_angle " << tot_angle << endl;
            viz_hit(curr_x, curr_y);
        }
        cout << hit.range << "@" << hit.angle << endl;
    }

    if (robot->ranges.size() < 5) {
        return;
    }

    float lft = clamp(0.0, robot->ranges[2].range, 2.0);
    float fwd = clamp(0.0, robot->ranges[3].range, 2.0);
    float rgt = clamp(0.0, robot->ranges[4].range, 2.0);
    cout << "lft,fwd,rgt = "
         << lft << ","
         << fwd << ","
         << rgt << endl;

    float spd = fwd - 1;
    float trn = clamp(-1.0, lft - rgt, 1.0);

    if (fwd < 1.2) {
      spd = 0;
      trn = 1;
    }

    cout << "spd,trn = " << spd << "," << trn << endl;
    robot->set_vel(spd + trn, spd - trn);

    
    cout << "x,y,t = "
         << robot->pos_x << ","
         << robot->pos_y << ","
         << robot->pos_t << endl;
    //robot->set_vel(robot->pos_t, -robot->pos_t);
    
}

void
robot_thread(Robot* robot)
{
    robot->do_stuff();
}

int
main(int argc, char* argv[])
{
    cout << "making robot" << endl;
    Robot robot(argc, argv, callback);
    std::thread rthr(robot_thread, &robot);

    return viz_run(argc, argv);
}
