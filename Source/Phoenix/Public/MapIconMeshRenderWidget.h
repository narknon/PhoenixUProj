#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Blueprint/UserWidget.h"
#include "EBeaconState.h"
#include "MapIconMeshRenderWidget.generated.h"

class UBeaconInfo;
class UMapIconInstance;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;
class URUserVectorArtData;
class UTexture2D;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UMapIconMeshRenderWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumIcons;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* MaterialDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URUserVectorArtData* MeshAsset;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UBeaconInfo>> BeaconsInList;
    
public:
    UMapIconMeshRenderWidget();
    UFUNCTION(BlueprintCallable)
    void SetTexture(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable)
    void SetOutlineTexture(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable)
    void SetName(const FString& pName);
    
    UFUNCTION(BlueprintCallable)
    void SetMaterial(UMaterialInterface* pMaterial);
    
    UFUNCTION(BlueprintCallable)
    void SetLayer3Texture(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable)
    void SetLayer2Texture(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentTextureName(const FString& pTextureName);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentBeaconState(EBeaconState pCurrentBeaconState);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveIcon(UMapIconInstance* Icon);
    
private:
    UFUNCTION(BlueprintCallable)
    void IconTextureCallback(UTexture2D* Texture, UObject* Param);
    
public:
    UFUNCTION(BlueprintCallable)
    FString GetWidgetName();
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetMaterialDynamic();
    
    UFUNCTION(BlueprintCallable)
    UMaterialInterface* GetMaterial();
    
    UFUNCTION(BlueprintCallable)
    FString GetCurrentTextureName();
    
    UFUNCTION(BlueprintCallable)
    EBeaconState GetCurrentBeaconState();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintPure)
    FLinearColor GetColorAndOpacity() const;
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* CreateMaterial(UMaterialInterface* pMaterial);
    
    UFUNCTION(BlueprintCallable)
    bool CONTAINS(UMapIconInstance* Icon);
    
    UFUNCTION(BlueprintCallable)
    void ClearIcons();
    
    UFUNCTION(BlueprintCallable)
    void ClearBeaconList();
    
    UFUNCTION(BlueprintCallable)
    void AddIconToList(UMapIconInstance* MapIconInstance);
    
    UFUNCTION(BlueprintCallable)
    UMapIconInstance* AddIcon(UBeaconInfo* Beacon, FVector2D Position, float Scale, float flags, FLinearColor Color);
    
    UFUNCTION(BlueprintCallable)
    void AddBeaconToList(UBeaconInfo* pBeaconInfo);
    
};

