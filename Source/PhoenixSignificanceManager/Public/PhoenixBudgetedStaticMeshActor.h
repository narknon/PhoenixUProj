#pragma once
#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "ESignificanceBiasEnum.h"
#include "SignificanceInterface.h"
#include "PhoenixBudgetedStaticMeshActor.generated.h"

UCLASS(Blueprintable)
class PHOENIXSIGNIFICANCEMANAGER_API APhoenixBudgetedStaticMeshActor : public AStaticMeshActor, public ISignificanceInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESignificanceBiasEnum DefaultSignificanceBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowRegistrationWithSignificanceManager;
    
public:
    APhoenixBudgetedStaticMeshActor(const FObjectInitializer& ObjectInitializer);
    
    // Fix for true pure virtual functions not being implemented
};

