#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Chaos/ChaosEngineInterface.h"
#include "AddOnMeshesChangedDynamicDelegateDelegate.h"
#include "CharacterLoadCompleteDelegate.h"
#include "CharacterLoadCompleteDynamicDelegateDelegate.h"
#include "CharacterOutfitLoadCompleteDelegate.h"
#include "EGenderEnum.h"
#include "GearLoadCompleteDelegate.h"
#include "Outfit.h"
#include "OutfitType.h"
#include "Templates/SubclassOf.h"
#include "CustomizableCharacterComponent.generated.h"

class AActor;
class UAddOnMesh;
class UAddOnMeshProperties;
class UCustomizableCharacterDefinition;
class UObject;
class UPoseAsset;
class UTexture;
class UTexture2D;
class UTextureRenderTarget2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class CUSTOMIZABLECHARACTER_API UCustomizableCharacterComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName CharacterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EGenderEnum Gender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterLoadComplete OnCharacterLoadComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterOutfitLoadComplete OnCharacterOutfitLoadComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAddOnMeshesChangedDynamicDelegate OnAddOnMeshesChangedDynamicDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGearLoadComplete OnGearFinishedLoading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOutfitType CurrentOutfit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FOutfit> Outfits;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoAsyncLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UAddOnMesh*> AddOnMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UAddOnMeshProperties*> CharacterItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAddOnMesh* MergedMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPoseAsset* HeadPoseAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPoseAsset* FacialPoseAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterDefinition* CurrentCCDLoading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterDefinition* CacheCCD;
    
public:
    UCustomizableCharacterComponent();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static AActor* SpawnEditorCharacter(const UObject* InWorldContextObject, const FTransform& InTransform, FName InCharacterID, TSubclassOf<AActor> CharacterClass, const FCharacterLoadCompleteDynamicDelegate& InLoadCompleteFromSpawnDelegate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FName> SortNames(TArray<FName> Names);
    
    UFUNCTION(BlueprintCallable)
    void SetVectorParameter(FName MeshName, FName ParameterName, FLinearColor Value, bool bResetMaterialParameters);
    
    UFUNCTION(BlueprintCallable)
    void SetTextureParameter(FName MeshName, FName ParameterName, UTexture* Texture, bool bResetMaterialParameters);
    
    UFUNCTION(BlueprintCallable)
    void SetScaleRootMotion(bool State);
    
    UFUNCTION(BlueprintCallable)
    void SetScale(float NewScale);
    
    UFUNCTION(BlueprintCallable)
    void SetScalarParameter(FName MeshName, FName ParameterName, float Value, bool bResetMaterialParameters);
    
    UFUNCTION(BlueprintCallable)
    void SetForcedLOD(int32 LOD, bool bInFOV);
    
    UFUNCTION(BlueprintCallable)
    void SetFlipped(FName CharacterPieceType, bool bFlip);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentOutfit(FName OutfitName);
    
    UFUNCTION(BlueprintCallable)
    void SetCharacterID(FName InRegistryID);
    
    UFUNCTION(BlueprintCallable)
    void SetBoneSliderScale(FName BoneName, float Value);
    
    UFUNCTION(BlueprintCallable)
    bool SetAsyncLoad(const bool bInAsyncLoad);
    
    UFUNCTION(BlueprintCallable)
    void SetAnimInstanceClass(UClass* NewClass);
    
    UFUNCTION(BlueprintCallable)
    void SetAddOnMesh(FName CharacterPieceType, FName CharacterPieceName, bool bResetMaterialParams);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UTexture* ResolveTextureSoftObjectReference(const TSoftObjectPtr<UTexture>& TexturePtr);
    
    UFUNCTION(BlueprintCallable)
    bool ResetOverridenVectorParameter(FName MeshName, FName ParameterName);
    
    UFUNCTION(BlueprintCallable)
    bool ResetOverridenTextureParameter(FName MeshName, FName ParameterName);
    
    UFUNCTION(BlueprintCallable)
    bool ResetOverridenScalarParameter(FName MeshName, FName ParameterName);
    
    UFUNCTION(BlueprintCallable)
    void ReloadCharacter();
    
    UFUNCTION(BlueprintCallable)
    void RecreateClothingActors();
    
    UFUNCTION(BlueprintCallable)
    void RebuildAddOnMeshes();
    
    UFUNCTION(BlueprintCallable)
    bool IsVectorParameterOverriden(FName MeshName, FName ParameterName);
    
    UFUNCTION(BlueprintCallable)
    bool IsTextureParameterOverriden(FName MeshName, FName ParameterName);
    
    UFUNCTION(BlueprintCallable)
    bool IsScalarParameterOverriden(FName MeshName, FName ParameterName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLoading() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAsyncLoad() const;
    
    UFUNCTION(BlueprintCallable)
    TMap<FName, FLinearColor> GetVectorParameters(FName MeshName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetVectorParameterDefault(FName MeshName, FName ParameterName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetVectorParameter(FName MeshName, FName ParameterName) const;
    
    UFUNCTION(BlueprintCallable)
    FName GetTypeClassication();
    
    UFUNCTION(BlueprintCallable)
    TMap<FName, UTexture*> GetTextureParameters(FName MeshName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture* GetTextureParameterDefault(FName MeshName, FName ParameterName) const;
    
    UFUNCTION(BlueprintCallable)
    UTexture* GetTextureParameter(FName MeshName, FName ParameterName);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<EPhysicalSurface> GetSurfaceTypeByName(FName SurfaceName);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<EPhysicalSurface> GetSurfaceTypeBelowActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSurfaceNameBelowActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSurfaceName(TEnumAsByte<EPhysicalSurface> SurfaceType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetSkeletalMeshName(FName MeshName) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetScaleRootMotion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetScale() const;
    
    UFUNCTION(BlueprintCallable)
    TMap<FName, float> GetScalarParameters(FName MeshName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetScalarParameterDefault(FName MeshName, FName ParameterName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetScalarParameter(FName MeshName, FName ParameterName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRandomStream GetRandomStream();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetRandomFloat();
    
    UFUNCTION(BlueprintCallable)
    static FColor GetRandomColorFromColorPalette();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<FName, FOutfit> GetOutfits();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMeshTriangleCount(FName Name, int32 LOD) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetMeshNames() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMeshDrawCount(FName Name, int32 LOD) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetLODInfo(int32 LOD, int32& TriangleCount, int32& DrawCallCount, int32& MeshCount) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAddOnMeshProperties* GetHeadAddOnMeshProperties();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FOutfit GetCurrentOutfit() const;
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetClassicationSubTypes(FName Classification);
    
    UFUNCTION(BlueprintCallable)
    static FName GetClassicationFromSubType(FName SubType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<FName, UAddOnMeshProperties*> GetCharacterItems() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCharacterID(FName& OutCharacterID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBoneSliderScale(FName BoneSliderName) const;
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetAllSurfaceNames();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FName> GetAllOutfitItemTypes();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetAllCharacterTypes();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetAllCharacterPieceClassifications();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FName> GetAllCharacterItemTypes();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetAllCharacterIDsOfTypeForEditor(FName SubtypeID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAddOnMeshProperties* GetAddOnMeshProperties(FName Name);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetAddOnMeshPieceName(FName Name) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<FName, UAddOnMesh*> GetAddOnMeshes() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetAddOnMeshBP(FName Name);
    
    UFUNCTION(BlueprintCallable)
    bool EditorSave();
    
    UFUNCTION(BlueprintCallable)
    void DrawSkeletalCapsules(FLinearColor Color, float LineThickness);
    
    UFUNCTION(BlueprintCallable)
    void DrawClothCapsules(FLinearColor Color, float LineThickness);
    
    UFUNCTION(BlueprintCallable)
    static UTexture2D* CreateTextureFromRenderTarget(UTextureRenderTarget2D* RenderTarget, const FString& PackageName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float ComputeBoundsScreenSize() const;
    
};

