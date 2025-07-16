// printer.cpp
#include "printer.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

namespace Printer {

    void printPoseVector(
        const std::string& label,
        const std::vector<std::vector<Pose>>& poses
    ) {
        std::ofstream out_file("outfile.txt", std::ios::app);
        if (!out_file) {
            std::cout << "Error: could not open outfile.txt\n";
        }
        out_file << label << "[";
        for (size_t i = 0; i < poses.size(); ++i) {
            for (size_t j = 0; j < poses[i].size(); ++j) {
                out_file
                    << "("
                    << std::fixed << std::setprecision(6)
                    << poses[i][j].x << "," 
                    << poses[i][j].y 
                    << ")";
                // print comma if this isn't the very last element
                if (i != poses.size() - 1 || j != poses[i].size() - 1) {
                    out_file << ",";
                }
            }
        }
        out_file << "]\n";
        out_file.close();
    }

    void printVelocityVector(
        const std::string& label,
        const std::vector<std::vector<VelocityPoseLayout>>& vels,
        const std::string& whichField
    ) {
        std::ofstream out_file("outfile.txt", std::ios::app);
        if (!out_file) {
            std::cout << "Error: could not open outfile.txt\n";
        }
        out_file << label << "[";
        for (size_t i = 0; i < vels.size(); ++i) {
            for (size_t j = 0; j < vels[i].size(); ++j) {
                float value = (whichField == "linear") 
                                ? vels[i][j].velocity.linear 
                                : vels[i][j].velocity.angular;
                out_file
                    << "("
                    << std::fixed << std::setprecision(6)
                    << vels[i][j].velocity.time << "," 
                    << value 
                    << ")";
                // same “not last element” test
                if (i != vels.size() - 1 || j != vels[i].size() - 1) {
                    out_file << ",";
                }
            }
        }
        out_file << "]\n";
        out_file.close();
    }
}
