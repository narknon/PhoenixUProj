#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/NoExportTypes.h"
#include "BTService_MissingNavmeshChecker.generated.h"

class AAIController;
class ANavigationData;

UCLASS(Blueprintable)
class BTUTILITYAI_API UBTService_MissingNavmeshChecker : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ErrorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HorzRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VertRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector LastGoodNavLocKey;
    
    UBTService_MissingNavmeshChecker();
protected:
    UFUNCTION(BlueprintCallable)
    static bool HasNavmesh(const AAIController* AIOwner, const ANavigationData* NavData, const FVector Location, const FVector Extent, FVector& OutLocation);
    
};

