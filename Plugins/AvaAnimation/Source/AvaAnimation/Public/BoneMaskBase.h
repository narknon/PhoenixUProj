#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "AnimMask.h"
#include "BoneMaskBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UBoneMaskBase : public UAnimMetaData, public IAnimMask {
    GENERATED_BODY()
public:
    UBoneMaskBase();
    
    // Fix for true pure virtual functions not being implemented
};

