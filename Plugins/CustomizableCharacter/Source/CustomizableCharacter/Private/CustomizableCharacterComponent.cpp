#include "CustomizableCharacterComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class UAddOnMesh;
class UAddOnMeshProperties;
class UObject;
class UTexture;
class UTexture2D;
class UTextureRenderTarget2D;

AActor* UCustomizableCharacterComponent::SpawnEditorCharacter(const UObject* InWorldContextObject, const FTransform& InTransform, FName InCharacterID, TSubclassOf<AActor> CharacterClass, const FCharacterLoadCompleteDynamicDelegate& InLoadCompleteFromSpawnDelegate) {
    return NULL;
}

TArray<FName> UCustomizableCharacterComponent::SortNames(TArray<FName> Names) {
    return TArray<FName>();
}

void UCustomizableCharacterComponent::SetVectorParameter(FName MeshName, FName ParameterName, FLinearColor Value, bool bResetMaterialParameters) {
}

void UCustomizableCharacterComponent::SetTextureParameter(FName MeshName, FName ParameterName, UTexture* Texture, bool bResetMaterialParameters) {
}

void UCustomizableCharacterComponent::SetScaleRootMotion(bool State) {
}

void UCustomizableCharacterComponent::SetScale(float NewScale) {
}

void UCustomizableCharacterComponent::SetScalarParameter(FName MeshName, FName ParameterName, float Value, bool bResetMaterialParameters) {
}

void UCustomizableCharacterComponent::SetForcedLOD(int32 LOD, bool bInFOV) {
}

void UCustomizableCharacterComponent::SetFlipped(FName CharacterPieceType, bool bFlip) {
}

void UCustomizableCharacterComponent::SetCurrentOutfit(FName OutfitName) {
}

void UCustomizableCharacterComponent::SetCharacterID(FName InRegistryID) {
}

void UCustomizableCharacterComponent::SetBoneSliderScale(FName BoneName, float Value) {
}

bool UCustomizableCharacterComponent::SetAsyncLoad(const bool bInAsyncLoad) {
    return false;
}

void UCustomizableCharacterComponent::SetAnimInstanceClass(UClass* NewClass) {
}

void UCustomizableCharacterComponent::SetAddOnMesh(FName CharacterPieceType, FName CharacterPieceName, bool bResetMaterialParams) {
}

UTexture* UCustomizableCharacterComponent::ResolveTextureSoftObjectReference(const TSoftObjectPtr<UTexture>& TexturePtr) {
    return NULL;
}

bool UCustomizableCharacterComponent::ResetOverridenVectorParameter(FName MeshName, FName ParameterName) {
    return false;
}

bool UCustomizableCharacterComponent::ResetOverridenTextureParameter(FName MeshName, FName ParameterName) {
    return false;
}

bool UCustomizableCharacterComponent::ResetOverridenScalarParameter(FName MeshName, FName ParameterName) {
    return false;
}

void UCustomizableCharacterComponent::ReloadCharacter() {
}

void UCustomizableCharacterComponent::RecreateClothingActors() {
}

void UCustomizableCharacterComponent::RebuildAddOnMeshes() {
}

bool UCustomizableCharacterComponent::IsVectorParameterOverriden(FName MeshName, FName ParameterName) {
    return false;
}

bool UCustomizableCharacterComponent::IsTextureParameterOverriden(FName MeshName, FName ParameterName) {
    return false;
}

bool UCustomizableCharacterComponent::IsScalarParameterOverriden(FName MeshName, FName ParameterName) {
    return false;
}

bool UCustomizableCharacterComponent::IsLoading() const {
    return false;
}

bool UCustomizableCharacterComponent::IsAsyncLoad() const {
    return false;
}

TMap<FName, FLinearColor> UCustomizableCharacterComponent::GetVectorParameters(FName MeshName) {
    return TMap<FName, FLinearColor>();
}

FLinearColor UCustomizableCharacterComponent::GetVectorParameterDefault(FName MeshName, FName ParameterName) const {
    return FLinearColor{};
}

FLinearColor UCustomizableCharacterComponent::GetVectorParameter(FName MeshName, FName ParameterName) const {
    return FLinearColor{};
}

FName UCustomizableCharacterComponent::GetTypeClassication() {
    return NAME_None;
}

TMap<FName, UTexture*> UCustomizableCharacterComponent::GetTextureParameters(FName MeshName) {
    return TMap<FName, UTexture*>();
}

UTexture* UCustomizableCharacterComponent::GetTextureParameterDefault(FName MeshName, FName ParameterName) const {
    return NULL;
}

UTexture* UCustomizableCharacterComponent::GetTextureParameter(FName MeshName, FName ParameterName) {
    return NULL;
}

TEnumAsByte<EPhysicalSurface> UCustomizableCharacterComponent::GetSurfaceTypeByName(FName SurfaceName) {
    return SurfaceType_Default;
}

TEnumAsByte<EPhysicalSurface> UCustomizableCharacterComponent::GetSurfaceTypeBelowActor(AActor* Actor) {
    return SurfaceType_Default;
}

FName UCustomizableCharacterComponent::GetSurfaceNameBelowActor(AActor* Actor) {
    return NAME_None;
}

FName UCustomizableCharacterComponent::GetSurfaceName(TEnumAsByte<EPhysicalSurface> SurfaceType) {
    return NAME_None;
}

FName UCustomizableCharacterComponent::GetSkeletalMeshName(FName MeshName) const {
    return NAME_None;
}

bool UCustomizableCharacterComponent::GetScaleRootMotion() {
    return false;
}

float UCustomizableCharacterComponent::GetScale() const {
    return 0.0f;
}

TMap<FName, float> UCustomizableCharacterComponent::GetScalarParameters(FName MeshName) {
    return TMap<FName, float>();
}

float UCustomizableCharacterComponent::GetScalarParameterDefault(FName MeshName, FName ParameterName) const {
    return 0.0f;
}

float UCustomizableCharacterComponent::GetScalarParameter(FName MeshName, FName ParameterName) const {
    return 0.0f;
}

FRandomStream UCustomizableCharacterComponent::GetRandomStream() {
    return FRandomStream{};
}

float UCustomizableCharacterComponent::GetRandomFloat() {
    return 0.0f;
}

FColor UCustomizableCharacterComponent::GetRandomColorFromColorPalette() {
    return FColor{};
}

TMap<FName, FOutfit> UCustomizableCharacterComponent::GetOutfits() {
    return TMap<FName, FOutfit>();
}

int32 UCustomizableCharacterComponent::GetMeshTriangleCount(FName Name, int32 LOD) const {
    return 0;
}

TArray<FName> UCustomizableCharacterComponent::GetMeshNames() const {
    return TArray<FName>();
}

int32 UCustomizableCharacterComponent::GetMeshDrawCount(FName Name, int32 LOD) const {
    return 0;
}

void UCustomizableCharacterComponent::GetLODInfo(int32 LOD, int32& TriangleCount, int32& DrawCallCount, int32& MeshCount) const {
}

UAddOnMeshProperties* UCustomizableCharacterComponent::GetHeadAddOnMeshProperties() {
    return NULL;
}

FOutfit UCustomizableCharacterComponent::GetCurrentOutfit() const {
    return FOutfit{};
}

TArray<FName> UCustomizableCharacterComponent::GetClassicationSubTypes(FName Classification) {
    return TArray<FName>();
}

FName UCustomizableCharacterComponent::GetClassicationFromSubType(FName SubType) {
    return NAME_None;
}

TMap<FName, UAddOnMeshProperties*> UCustomizableCharacterComponent::GetCharacterItems() const {
    return TMap<FName, UAddOnMeshProperties*>();
}

bool UCustomizableCharacterComponent::GetCharacterID(FName& OutCharacterID) const {
    return false;
}

float UCustomizableCharacterComponent::GetBoneSliderScale(FName BoneSliderName) const {
    return 0.0f;
}

TArray<FName> UCustomizableCharacterComponent::GetAllSurfaceNames() {
    return TArray<FName>();
}

TArray<FName> UCustomizableCharacterComponent::GetAllOutfitItemTypes() {
    return TArray<FName>();
}

TArray<FName> UCustomizableCharacterComponent::GetAllCharacterTypes() {
    return TArray<FName>();
}

TArray<FName> UCustomizableCharacterComponent::GetAllCharacterPieceClassifications() {
    return TArray<FName>();
}

TArray<FName> UCustomizableCharacterComponent::GetAllCharacterItemTypes() {
    return TArray<FName>();
}

TArray<FName> UCustomizableCharacterComponent::GetAllCharacterIDsOfTypeForEditor(FName SubtypeID) {
    return TArray<FName>();
}

UAddOnMeshProperties* UCustomizableCharacterComponent::GetAddOnMeshProperties(FName Name) {
    return NULL;
}

FName UCustomizableCharacterComponent::GetAddOnMeshPieceName(FName Name) const {
    return NAME_None;
}

TMap<FName, UAddOnMesh*> UCustomizableCharacterComponent::GetAddOnMeshes() const {
    return TMap<FName, UAddOnMesh*>();
}

bool UCustomizableCharacterComponent::GetAddOnMeshBP(FName Name) {
    return false;
}

bool UCustomizableCharacterComponent::EditorSave() {
    return false;
}

void UCustomizableCharacterComponent::DrawSkeletalCapsules(FLinearColor Color, float LineThickness) {
}

void UCustomizableCharacterComponent::DrawClothCapsules(FLinearColor Color, float LineThickness) {
}

UTexture2D* UCustomizableCharacterComponent::CreateTextureFromRenderTarget(UTextureRenderTarget2D* RenderTarget, const FString& PackageName) {
    return NULL;
}

float UCustomizableCharacterComponent::ComputeBoundsScreenSize() const {
    return 0.0f;
}

UCustomizableCharacterComponent::UCustomizableCharacterComponent() {
    this->Gender = EGenderEnum::GENDER_UNKNOWN;
    this->bDoAsyncLoad = true;
    this->MergedMesh = NULL;
    this->HeadPoseAsset = NULL;
    this->FacialPoseAsset = NULL;
    this->CurrentCCDLoading = NULL;
    this->CacheCCD = NULL;
}

