#pragma once
#include "CoreMinimal.h"
#include "MasterOverlapThrottlerSettings.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct MASTEROVERLAPTHROTTLER_API FMasterOverlapThrottlerSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NoOverlapEventsRadiusMeters;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> ComparisonActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bManageOverlapsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bManageCollisionEnabled;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPhysicsCollisionsEnabled;
    
    FMasterOverlapThrottlerSettings();
};

