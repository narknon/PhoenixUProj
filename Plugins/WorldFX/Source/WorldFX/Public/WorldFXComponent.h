#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldFXComponentBase.h"
#include "WorldFXFull.h"
#include "WorldFXComponent.generated.h"

class USceneComponent;
class UWorldFXComponent;
class UWorldFXRule;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WORLDFX_API UWorldFXComponent : public UWorldFXComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXRule* Rule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXFull WorldFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnAttached;
    
    UWorldFXComponent();
    UFUNCTION(BlueprintCallable)
    void SetSpawnAttached(bool bNewSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    void ResetCascadeParameters();
    
    UFUNCTION(BlueprintCallable)
    void RefreshCascadeParameters();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetSpawnAttached(bool& bIsSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    static UWorldFXComponent* CreateWorldFX(USceneComponent* AttachTo, FWorldFXFull WorldFXSetup, FTransform RelativeTransform);
    
};

