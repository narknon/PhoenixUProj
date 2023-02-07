#include "Subtitles.h"

class UVerticalBox;

void USubtitles::Setup() {
}

void USubtitles::EvaluateSubtitleVerticalBox(UVerticalBox* Subtitle_VerticalBox) {
}






USubtitles::USubtitles() : UUserWidget(FObjectInitializer::Get()) {
    this->BP_Subtitle_Box = NULL;
    this->Subtitle_Box = NULL;
    this->Subtitle_Box_LowPriority = NULL;
}

