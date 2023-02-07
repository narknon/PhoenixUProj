#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightExtraParameter.h"
#include "AnimatedLightExtraSetupMaterialParameter.h"
#include "AnimatedLightExtraSetupNiagaraParameter.h"
#include "AnimatedLightParametersComponentAuto.h"
#include "AnimatedLightParametersComponent.generated.h"

class UMaterialInstanceDynamic;
class UNiagaraComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ANIMATEDLIGHTS_API UAnimatedLightParametersComponent : public UAnimatedLightParametersComponentAuto {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimatedLightExtraSetupMaterialParameter> MaterialParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimatedLightExtraSetupNiagaraParameter> NiagaraParameters;
    
    UAnimatedLightParametersComponent();
    UFUNCTION(BlueprintCallable)
    bool RemoveAnimatedLightParameters();
    
    UFUNCTION(BlueprintCallable)
    bool RemoveAnimatedLightParameter(FName Parameter);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveAnimatedLightNiagaraParameters(UNiagaraComponent* NiagaraComponent);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveAnimatedLightNiagaraParameter(FName Parameter);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveAnimatedLightMaterialParameters(UMaterialInstanceDynamic* MaterialInstanceDynamic);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveAnimatedLightMaterialParameter(FName Parameter);
    
    UFUNCTION(BlueprintCallable)
    bool AddAnimatedLightNiagaraParameters(UNiagaraComponent* NiagaraComponent, TArray<FAnimatedLightExtraParameter> ParameterList);
    
    UFUNCTION(BlueprintCallable)
    bool AddAnimatedLightNiagaraParameter(UNiagaraComponent* NiagaraComponent, FAnimatedLightExtraParameter Parameter);
    
    UFUNCTION(BlueprintCallable)
    bool AddAnimatedLightMaterialParameters(UMaterialInstanceDynamic* MaterialInstanceDynamic, TArray<FAnimatedLightExtraParameter> ParameterList);
    
    UFUNCTION(BlueprintCallable)
    bool AddAnimatedLightMaterialParameter(UMaterialInstanceDynamic* MaterialInstanceDynamic, FAnimatedLightExtraParameter Parameter);
    
};

