#include "MaxRectsBinPack.h"
#include "bpInterface.h"
#include <cstdio>
#include <iostream>

using namespace rbp;

bool lcomparator ( const item& l, const item& r)
    { return l.length > r.length; }

bool wcomparator ( const item& l, const item& r)
    { return l.width > r.width; }

bool acomparator ( const item& l, const item& r)
    { return l.area > r.area; }

bool idcomparator ( const item& l, const item& r)
    { return l.id < r.id; }

bpInterface::bpInterface(){
	bin.Init(20, 40);
}

bool bpInterface::packHelper(std::vector<item> &nonseq){
    bin.Init(20, 40);

    for (int i = 0; i < (int)nonseq.size(); ++i)
    {
        // Perform the packing.
        // MaxRectsBinPack::FreeRectChoiceHeuristic heuristic = MaxRectsBinPack::RectBestAreaFit; // This can be changed individually even for each rectangle packed.
        // Rect packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
        // if (packedRect.height > 0){
        //  //printf("Packed to (x,y)=(%d,%d), (w,h)=(%d,%d). Free space left: %.2f%%\n", packedRect.x, packedRect.y, packedRect.width, packedRect.height, 100.f - bin.Occupancy()*100.f);
        // }else{
  //           //printf("Failed! Could not find a proper position to pack this rectangle into. Skipping this one.\n");
        //  return 0;
        //  //printf("Failed! Could not find a proper position to pack this rectangle into. Skipping this one.\n");
        // }
        // MaxRectsBinPack::FreeRectChoiceHeuristic heuristic = MaxRectsBinPack::RectBestAreaFit; // This can be changed individually even for each rectangle packed.
        // Rect packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
        // if (packedRect.height > 0){
        //     //printf("Packed to (x,y)=(%d,%d), (w,h)=(%d,%d). Free space left: %.2f%%\n", packedRect.x, packedRect.y, packedRect.width, packedRect.height, 100.f - bin.Occupancy()*100.f);
        // }else{
        //     heuristic = MaxRectsBinPack::RectBestShortSideFit;
        //     packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
        //     if (packedRect.height > 0){
        //         //printf("Packed to (x,y)=(%d,%d), (w,h)=(%d,%d). Free space left: %.2f%%\n", packedRect.x, packedRect.y, packedRect.width, packedRect.height, 100.f - bin.Occupancy()*100.f);
        //     } else {
        //         heuristic = MaxRectsBinPack::RectBestLongSideFit;
        //         packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
        //         if (packedRect.height > 0){
        //             //printf("Packed to (x,y)=(%d,%d), (w,h)=(%d,%d). Free space left: %.2f%%\n", packedRect.x, packedRect.y, packedRect.width, packedRect.height, 100.f - bin.Occupancy()*100.f);
        //         } else {
        //             heuristic = MaxRectsBinPack::RectBottomLeftRule;
        //             packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
        //             if (packedRect.height > 0){
        //                 //printf("Packed to (x,y)=(%d,%d), (w,h)=(%d,%d). Free space left: %.2f%%\n", packedRect.x, packedRect.y, packedRect.width, packedRect.height, 100.f - bin.Occupancy()*100.f);
        //             } else {
        //                 heuristic = MaxRectsBinPack::RectContactPointRule;
        //                 packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
        //                 if (packedRect.height > 0){
        //                     //printf("Packed to (x,y)=(%d,%d), (w,h)=(%d,%d). Free space left: %.2f%%\n", packedRect.x, packedRect.y, packedRect.width, packedRect.height, 100.f - bin.Occupancy()*100.f);
        //                 } else {
        //                     //printf("Failed! Could not find a proper position to pack this rectangle into. Skipping this one.\n");
        //                     return 0;
        //                 }
        //             }
        //         }
        //     }
        //     //printf("Failed! Could not find a proper position to pack this rectangle into. Skipping this one.\n");
        // }


        MaxRectsBinPack::FreeRectChoiceHeuristic heuristic = MaxRectsBinPack::RectBestAreaFit; // This can be changed individually even for each rectangle packed.
        Rect packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
        if (packedRect.height > 0){
            nonseq[i].x = packedRect.x;
            nonseq[i].y = packedRect.y;
            //printf("Packed to (x,y)=(%d,%d), (w,h)=(%d,%d). Free space left: %.2f%%\n", packedRect.x, packedRect.y, packedRect.width, packedRect.height, 100.f - bin.Occupancy()*100.f);
        }else{
            //printf("Failed! Could not find a proper position to pack this rectangle into. Skipping this one.\n");
            return 0;
        }
    }

    return 1;
}

void bpInterface::updateIDs(std::vector<customer> &customers, std::vector<item> &nonseq){
    std::sort(nonseq.begin(), nonseq.end(), idcomparator);

    for (int i = 0; i < (int)customers.size(); ++i)
    {
        for (int j = 0; j < (int)customers[i].items.size(); ++j)
        {
            customers[i].items[j].x = nonseq[customers[i].items[j].id].x;
            customers[i].items[j].y = nonseq[customers[i].items[j].id].y;
        }

    }
}

bool bpInterface::pack(std::vector<customer> &customers){
    std::vector<item> nonseq;
    // sequential
    for (int i = 0; i < (int)customers.size(); ++i)
    {
        for (int j = 0; j < (int)customers[i].items.size(); ++j)
        {
            nonseq.push_back(item());
            nonseq[(int)nonseq.size()-1].width = customers[i].items[j].width;
            nonseq[(int)nonseq.size()-1].length = customers[i].items[j].length;
            nonseq[(int)nonseq.size()-1].area = customers[i].items[j].area;
            nonseq[(int)nonseq.size()-1].id = customers[i].items[j].id;
        }

    }

    if (packHelper(nonseq) == 1){
        updateIDs(customers, nonseq);
        return 1;
    }

    // // non seq

    std::sort(nonseq.begin(), nonseq.end(), acomparator);

    if (packHelper(nonseq) == 1){
        updateIDs(customers, nonseq);
        return 1;
    }

    std::sort(nonseq.begin(), nonseq.end(), lcomparator);

    if (packHelper(nonseq) == 1){
        updateIDs(customers, nonseq);
        return 1;
    }

    std::sort(nonseq.begin(), nonseq.end(), wcomparator);

    if (packHelper(nonseq) == 1){
        updateIDs(customers, nonseq);
        return 1;
    }



    return 0;

    // std::cout << "attempting to pack: " << std::endl;

    // for (int i = 0; i < (int)nonseq.size(); ++i)
    // {
    //     std::cout << nonseq[i].width << " " << nonseq[i].length << std::endl;
    // }


}