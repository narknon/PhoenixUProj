#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation_Bool.h"
#include "CreatureLookAtTargetEvaluation_MatchingSubtypes.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_MatchingSubtypes : public UCreatureLookAtTargetEvaluation_Bool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CreatureTypeID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetTypeID;
    
    UCreatureLookAtTargetEvaluation_MatchingSubtypes();
};

