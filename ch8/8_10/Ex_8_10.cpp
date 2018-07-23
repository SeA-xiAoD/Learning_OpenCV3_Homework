#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>


typedef struct _my_struct{
    int integer;
    cv::Point point;
    cv::Rect rect;
} my_struct;


void write_my_struct(cv::FileStorage& fs, const std::string& name, const my_struct& ms)
{
    /*
     * fs: the file storage you want to write to
     * name: the ms's tag
     * ms: the ms you want to write
     */

    fs << name << "{";
    fs << "integer" << ms.integer;
    fs << "point" << ms.point;
    fs << "rect" << ms.rect;
    fs << "}";
}


void read_my_struct(cv::FileStorage& fs, const cv::FileNode& ms_node, my_struct& ms)
{
    /*
     * fs: I didn't use fs here
     * ms_node: The node of the struct
     */

    cv::FileNode this_struct = ms_node;
    cv::FileNodeIterator it = this_struct.begin(), it_end = this_struct.end();
    *it >> ms.integer;
    it++;
    *it >> ms.point;
    it++;
    *it >> ms.rect;
}


int main(int argc, char **argv)
{
    my_struct ms[10];
    my_struct conv_ms[10]; // to store the converse of ms

    for(int i = 0; i < 10; i++)
    {
        ms[i].integer = i;
        ms[i].point = cv::Point(i, i);
        ms[i].rect = cv::Rect(cv::Point(0,0), cv::Point(i, i));
    }

    // write file
    cv::FileStorage fs;
    for(int i = 0; i < 10; i++)
    {
        if(i == 0)
            fs = cv::FileStorage("Ex_8_10.yml", cv::FileStorage::WRITE);
        else
            fs = cv::FileStorage("Ex_8_10.yml", cv::FileStorage::APPEND);
        write_my_struct(fs, "my_struct_" + std::to_string(i), ms[i]);
        fs.release();
    }

    // read file
    for(int i = 0; i < 10; i++)
    {
        fs = cv::FileStorage("Ex_8_10.yml", cv::FileStorage::READ);
        cv::FileNode fn = fs["my_struct_" + std::to_string(9 - i)];
        read_my_struct(fs, fn, conv_ms[i]);
    }

    // verification
    for(int i = 0; i < 10; i++)
    {
        std::cout << "conv_my_struct_" + std::to_string(i) << ":" << std::endl;
        std::cout << conv_ms[i].integer << std::endl;
        std::cout << conv_ms[i].point << std::endl;
        std::cout << conv_ms[i].rect << std::endl << std::endl;
    }

    return 0;
}