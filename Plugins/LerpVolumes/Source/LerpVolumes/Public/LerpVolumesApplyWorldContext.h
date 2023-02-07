#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesApplyWorldContext.generated.h"

class AActor;
class UMaterialParameterCollection;
class UMaterialParameterCollectionInstance;
class UNiagaraParameterCollection;
class UNiagaraParameterCollectionInstance;
class UWorld;

USTRUCT(BlueprintType)
struct FLerpVolumesApplyWorldContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorld* World;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* sender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Receiver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMaterialParameterCollection*, UMaterialParameterCollectionInstance*> MPCs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UNiagaraParameterCollection*, UNiagaraParameterCollectionInstance*> NPCs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Mode;
    
    LERPVOLUMES_API FLerpVolumesApplyWorldContext();
};

