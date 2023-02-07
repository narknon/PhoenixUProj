#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionCharacterIsOverlappingSelfCreature.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionCharacterIsOverlappingSelfCreature : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SelfCreatureCapsuleRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OptionCharacterCapsuleRadiusMultiplier;
    
public:
    UOptionCharacterIsOverlappingSelfCreature();
};

