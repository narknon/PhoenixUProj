#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation_Bool.h"
#include "Templates/SubclassOf.h"
#include "CreatureLookAtTargetEvaluation_IsClass.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_IsClass : public UCreatureLookAtTargetEvaluation_Bool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> Class;
    
    UCreatureLookAtTargetEvaluation_IsClass();
};

