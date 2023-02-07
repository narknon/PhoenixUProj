#pragma once
#include "CoreMinimal.h"
#include "QualifierOptions.h"
#include "Templates/SubclassOf.h"
#include "ActorsofClassWithinRangeQualifierOptions.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UActorsofClassWithinRangeQualifierOptions : public UQualifierOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorType;
    
    UActorsofClassWithinRangeQualifierOptions();
};

