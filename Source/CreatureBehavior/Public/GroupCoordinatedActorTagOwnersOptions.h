#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "QualifierOptions.h"
#include "GroupCoordinatedActorTagOwnersOptions.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CREATUREBEHAVIOR_API UGroupCoordinatedActorTagOwnersOptions : public UQualifierOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> TagIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector SubjectToCheck;
    
    UGroupCoordinatedActorTagOwnersOptions();
};

