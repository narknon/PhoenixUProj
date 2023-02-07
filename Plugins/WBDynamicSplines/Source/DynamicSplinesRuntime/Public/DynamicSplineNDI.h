#pragma once
#include "CoreMinimal.h"
#include "NiagaraDataInterface.h"
#include "DynamicSplineUsage.h"
#include "DynamicSplineNDI.generated.h"

class AActor;
class UDynamicSplineSet;
class USkeletalMeshComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable, EditInlineNew)
class DYNAMICSPLINESRUNTIME_API UDynamicSplineNDI : public UNiagaraDataInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* HostActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicSplineSet* SplineSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDynamicSplineUsage SplineUsage;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* ComputedSkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ComputedStaticMesh;
    
public:
    UDynamicSplineNDI();
};

