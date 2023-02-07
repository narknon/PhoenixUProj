#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_NiagaraEmitter.generated.h"

class UNiagaraSystem;
class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_NiagaraEmitter : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* System;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* EndPoint;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform LocalTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseLocalTransform;
    
    USceneAction_NiagaraEmitter();
};

