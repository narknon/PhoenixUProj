#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AddOnMesh.generated.h"

class UMaterialInstanceDynamic;
class UNiagaraComponent;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class CUSTOMIZABLECHARACTER_API UAddOnMesh : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UMaterialInstanceDynamic*> SlotNameToMaterialInstanceDynamicMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UNiagaraComponent*> NiagaraComponents;
    
public:
    UAddOnMesh();
};

