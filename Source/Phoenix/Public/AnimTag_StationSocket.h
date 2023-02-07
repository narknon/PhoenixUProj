#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "AnimTag_StationSocket.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimTag_StationSocket : public UAnimationArchitectTagProvider {
    GENERATED_BODY()
public:
    UAnimTag_StationSocket();
};

