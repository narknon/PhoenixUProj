#pragma once
#include "CoreMinimal.h"
#include "AdaptationOverrideInterface.h"
#include "EmissiveAdaptationFinalState.h"
#include "SceneRigActionState.h"
#include "SceneActionState_Adaptation.generated.h"

UCLASS(Blueprintable)
class USceneActionState_Adaptation : public USceneRigActionState, public IAdaptationOverrideInterface {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEmissiveAdaptationFinalState InitialState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInitialStateValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInserted;
    
    USceneActionState_Adaptation();
    
    // Fix for true pure virtual functions not being implemented
};

