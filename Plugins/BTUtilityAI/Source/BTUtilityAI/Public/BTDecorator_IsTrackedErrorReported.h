#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTDecorator_IsTrackedErrorReported_Base.h"
#include "EUtilityTrackedErrorType.h"
#include "BTDecorator_IsTrackedErrorReported.generated.h"

UCLASS(Blueprintable)
class BTUTILITYAI_API UBTDecorator_IsTrackedErrorReported : public UBTDecorator_IsTrackedErrorReported_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ErrorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAccessory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector AccessoryActorKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUtilityTrackedErrorType ErrorType;
    
    UBTDecorator_IsTrackedErrorReported();
};

