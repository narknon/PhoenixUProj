#pragma once
#include "CoreMinimal.h"
#include "EStationInteraction.h"
#include "StorySetupData.h"
#include "StationQueryData.generated.h"

class UStationComponent;

USTRUCT(BlueprintType)
struct FStationQueryData : public FStorySetupData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStationComponent> StationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ConnectionsBitmask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StationValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStationInteraction StationInteractionStatus;
    
    PHOENIX_API FStationQueryData();
};

