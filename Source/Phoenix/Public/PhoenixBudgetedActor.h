#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ClothBudgeterInterface.h"
#include "ESignificanceBiasEnum.h"
#include "LODBudgeterInterface.h"
#include "SignificanceInterface.h"
#include "PhoenixBudgetedActor.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API APhoenixBudgetedActor : public AActor, public ISignificanceInterface, public ILODBudgeterInterface, public IClothBudgeterInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESignificanceBiasEnum DefaultSignificanceBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowRegistrationWithSignificanceManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowRegistrationWithLODBudgeter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowRegistrationWithClothBudgeter;
    
public:
    APhoenixBudgetedActor(const FObjectInitializer& ObjectInitializer);
    
    // Fix for true pure virtual functions not being implemented
};

