#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Blueprint/UserWidget.h"
#include "SMeshWidgetParticleEmitterProperties.h"
#include "ParticleMeshRenderWidget.generated.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;
class URUserVectorArtData;
class UStaticMesh;
class UTexture2D;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UParticleMeshRenderWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSMeshWidgetParticleEmitterProperties Properties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* ParticleMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* ParticleTexture;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* MaterialDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URUserVectorArtData* MeshAsset;
    
public:
    UParticleMeshRenderWidget();
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void StopEmitter();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void StartEmitter();
    
    UFUNCTION(BlueprintCallable)
    void SetMaterial(UMaterialInterface* pMaterial);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintPure)
    FLinearColor GetColorAndOpacity() const;
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* CreateMaterial(UMaterialInterface* pMaterial);
    
};

