#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapRefreshType.h"
#include "MaterialSwapMeshPoolBase.h"
#include "MaterialSwapActor.generated.h"

class AActor;
class UMaterialSwapActor;

UCLASS(Blueprintable, NonTransient)
class MATERIALPERMUTER_API UMaterialSwapActor : public UMaterialSwapMeshPoolBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> SwappedActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapActor*> DependentSwaps;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMaterialSwapActor> RootSwap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EMaterialSwapRefreshType RefreshType;
    
public:
    UMaterialSwapActor();
};

