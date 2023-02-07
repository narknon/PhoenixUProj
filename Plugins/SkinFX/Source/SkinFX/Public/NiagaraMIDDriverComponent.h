#pragma once
#include "CoreMinimal.h"
#include "NiagaraMaterialDriverComponent.h"
#include "NiagaraMIDDriverComponent.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SKINFX_API UNiagaraMIDDriverComponent : public UNiagaraMaterialDriverComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMaterialInstanceDynamic>> MaterialInstanceDynamics;
    
    UNiagaraMIDDriverComponent();
    UFUNCTION(BlueprintCallable)
    void RemoveMID(UMaterialInstanceDynamic* Mid);
    
    UFUNCTION(BlueprintCallable)
    void EmptyMIDs();
    
    UFUNCTION(BlueprintCallable)
    void AddMID(UMaterialInstanceDynamic* Mid);
    
};

