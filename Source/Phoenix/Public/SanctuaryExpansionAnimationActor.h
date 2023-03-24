#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "SanctuaryExpansionAnimationActor.generated.h"

UCLASS(Abstract, Blueprintable)
class PHOENIX_API ASanctuaryExpansionAnimationActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo ExpansionID;
    
    ASanctuaryExpansionAnimationActor(const FObjectInitializer& ObjectInitializer);
};

