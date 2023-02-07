#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Actor_MissionStation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_MissionStation : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MissionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MissionUID;
    
    UActor_MissionStation();
};

