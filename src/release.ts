/**
 * Represents a release object.
 * @class Release
 * @property {boolean} private - Indicates whether the release is private or not.
 * @property {string} id - The unique identifier for the release.
 * @property {string} createdAt - The timestamp when the release was created.
 * @property {string} updatedAt - The timestamp when the release was last updated.
 * @property {string} name - The name of the release.
 * @property {string} channel - The channel for the release.
 * @property {string} version - The version of the release.
 * @property {string} platform - The platform for the release.
 * @property {string[]} platforms - An array of platforms for the release.
 * @property {string} notes - The release notes.
 * @property {number} totalFiles - The total number of files in the release.
 * @property {string} publishedAt - The timestamp when the release was published.
 * @property {Object[]} files - An array of files associated with the release.
 * @property {string} files.id - The unique identifier for the file.
 * @property {string} files.createdAt - The timestamp when the file was created.
 * @property {string} files.updatedAt - The timestamp when the file was last updated.
 * @property {string} files.name - The name of the file.
 * @property {string} files.url - The URL of the file.
 * @property {number} files.size - The size of the file in bytes.
 * @property {number} files.downloads - The number of times the file has been downloaded.
 * @property {string} files.extension - The file extension.
 * @property {string} files.checksum - The file checksum.
 * @property {boolean} files.secured - Indicates whether the file is secured or not.
 * @property {string} files.releaseId - The unique identifier for the release that this file is associated with.
 * @property {boolean} published - Indicates whether the release has been published or not.
 * @property {string} productId - The unique identifier for the product that this release is associated with.
 * @property {string} tenantId - The unique identifier for the tenant that this release is associated with.
 */
 
export class Release {
    '`private`'!: boolean
    id!: string;
    createdAt!: string;
    updatedAt!: string;
    name!: string;
    channel!: string;
    version!: string;
    platform!: string;
    platforms!: string[];
    notes!: string;
    totalFiles!: number;
    publishedAt!: string;
    files!: {
        id: string;
        createdAt: string;
        updatedAt: string;
        name: string;
        url: string;
        size: number;
        downloads: number;
        extension: string;
        checksum: string;
        secured: boolean;
        releaseId: string;
    }[];
    published!: boolean;
    productId!: string;
    tenantId!: string;
};