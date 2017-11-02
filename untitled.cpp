		MaxRectsBinPack::FreeRectChoiceHeuristic heuristic = MaxRectsBinPack::RectBestAreaFit; // This can be changed individually even for each rectangle packed.
		Rect packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
		if (packedRect.height > 0){
			//printf("Packed to (x,y)=(%d,%d), (w,h)=(%d,%d). Free space left: %.2f%%\n", packedRect.x, packedRect.y, packedRect.width, packedRect.height, 100.f - bin.Occupancy()*100.f);
		}else{
            heuristic = MaxRectsBinPack::RectBestShortSideFit;
			packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
            if (packedRect.height > 0){

            } else {
                heuristic = MaxRectsBinPack::RectBestLongSideFit;
                packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
                if (packedRect.height > 0){

                } else {
                    heuristic = MaxRectsBinPack::RectBottomLeftRule;
                    packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
                    if (packedRect.height > 0){

                    } else {
                        heuristic = MaxRectsBinPack::RectContactPointRule;
                        packedRect = bin.Insert(nonseq[i].width, nonseq[i].length, heuristic);
                        if (packedRect.height > 0){

                        } else {
                            //printf("Failed! Could not find a proper position to pack this rectangle into. Skipping this one.\n");
                            return 0;
                        }
                    }
                }
            }
			//printf("Failed! Could not find a proper position to pack this rectangle into. Skipping this one.\n");
		}