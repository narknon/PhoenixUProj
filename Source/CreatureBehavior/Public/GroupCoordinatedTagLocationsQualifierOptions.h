#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "QualifierOptions.h"
#include "GroupCoordinatedTagLocationsQualifierOptions.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CREATUREBEHAVIOR_API UGroupCoordinatedTagLocationsQualifierOptions : public UQualifierOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SearchRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector SearchAreaCentreKey;
    
    UGroupCoordinatedTagLocationsQualifierOptions();
};

