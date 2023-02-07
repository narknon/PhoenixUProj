#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "BTService_InvalidPathChecker.generated.h"

class AAIController;
class ANavigationData;
class UNavigationQueryFilter;

UCLASS(Blueprintable)
class BTUTILITYAI_API UBTService_InvalidPathChecker : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxChecksPerTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCacheRefreshTime_Empty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCacheRefreshTime_Valid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UNavigationQueryFilter> FilterClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisallowPartial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectionHeight;
    
    UBTService_InvalidPathChecker();
protected:
    UFUNCTION(BlueprintCallable)
    static bool CanPath(const AAIController* AIOwner, const ANavigationData* NavData, const FVector From, const FVector To, TSubclassOf<UNavigationQueryFilter> QueryFilter, bool bAllowPartial, float ProjRadius, float ProjHeight);
    
};

